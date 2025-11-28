# QT notes
A little doc with some QT tips and ideas. Please read official documentation for proper guides and full info.

## Contents

- [Contents](#contents)
- [Notes](#notes)
- [Debug](#debug)
  - [Usage](#usage)
- [Signal-Slot system](#signal-slot-system)
  - [Structure](#structure)
  - [Threads](#threads)
  - [How it works (simple version)](#how-it-works-simple-version)
  - [Example](#example)
- [Pop-up message](#pop-up-message)
- [File dialog](#file-dialog)
  - [Structure](#structure-1)
    - [Save file dialog](#save-file-dialog)
    - [Open file dialog](#open-file-dialog)
  - [Example](#example-1)
    - [Save file dialog](#save-file-dialog-1)
    - [Open file dialog](#open-file-dialog-1)
- [Color dialog](#color-dialog)
  - [Structure](#structure-2)
  - [Example](#example-2)
- [Multithreading](#multithreading)
  - [Example](#example-3)
- [Mouse tracking](#mouse-tracking)
  - [Example](#example-4)
- [3D graphic](#3d-graphic)
  - [Example](#example-5)
    - [OpenGL + Shaders](#opengl--shaders)


## Notes  

- QT allows not commercial free use and can be installed using installation tool from the official website or using console packaging installation.
- QT create is an easy-to-use tool that allows to visually create windows and design those. But it does not have a visual way to control all the options and design opportunities that QT presents, due to that manual in code control of the elements (widgets) is preferable.
- QT is preferably by default built using [CMake](/C&C++/Parts/Tools_notes.md#cmake)

## Debug
Even though QT creates the GUI window, it can be useful to have an instrument to output in the console window, mainly for the debugging reasons. For these purposes QT has ```<QDebug>``` library.

### Usage
``` c++
#include <QDebug>

...
//Anywhere in the code:
qDebug() <<"Debug message!";
...
```

## Signal-Slot system
The Qt Signal–Slot System is one of the core mechanisms that makes Qt applications clean, modular, and reactive. This system allows separate parts of the program to easily communicate with each other, even if these parts are from separated elements of the program.
Qt signals are like notifications and slots are handlers.
- A signal is emitted when something happens (button clicked, value changed, error occurred, timer fired…)
- A slot is a function that reacts to that signal.
- Qt automatically connects signals to slots using the `connect()` function.
- When the signal is emitted, all connected slots are called automatically (one signal can trigger several slots).
- A single slot can be triggered by many signals.
- Signal-Slot system makes Qt code extremely modular:
  - Qt objects do not need to know anything about each other (objects communicate through signals and slots):
    - The sender does not need the receiver’s header file.
    - The receiver does not need the sender’s implementation.

### Structure
- Class "A" has a declared signal:
    ```C++
    signals:
        void somethingHappened(int data);
    ```
    - Signals have no implementation. They’re just “markers.”
- Class "B" has a slot (slots are normal functions, just marked as slots): 
    ```C++
    public slots:
        void onSomethingHappened();
    ```
- They are connected at some point in the program (before actual signal handling) - usually in constructor of the parent class:
    ```C++
    connect(a, &A::somethingHappened,b, &B::onSomethingHappened); // "a" is pointer to an object of A class (same for "b")
    ```
- Object "a" emits a signal: `emit somethingHappened(int data);`
- Object "b" slot receives the signal and the connected slot is being executed.

```
Some event occurs
      ↓
Signal is emitted
      ↓
Qt event queue delivers connection
      ↓
Connected slot(s) are called
```

### Threads
If sender and receiver live in different threads, the slot is executed in the receiver’s thread.

Qt chooses automatically:
- If in **same thread** → *Direct connection*
  - like a normal function call
- If in **different threads** → *Queued connection*
  - signal goes into an event queue
  - slot executes later safely on receiver’s thread
  - 
This is why signals/slots are perfect for:
- background workers
- QThread usage
- file parsing callbacks
- OpenGL errors (as in your case)

### How it works (simple version)
When you run moc (Meta-Object Compiler), it:
- reads your class
- sees signals, slots, Q_OBJECT
- generates extra C++ code
- builds a runtime type system
- creates metadata for connections
  - This metadata allows:
    - dynamic invocation
    - threading
    - queued signals
    - introspection
    - automatic disconnection when objects are destroyed

Don’t need to manually handle any of this.

### Example
```C++
// modelviewer.h
class ModelViewer : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core { 
    ... 
    public:
        void ModelViewer::paintGL();
    signals: 
        void SignalPrintingError(const QString &message); 
    ...
}; 

// modelviewer.cpp
void ModelViewer::paintGL() { 
    try { 
        // some code to print the model
    } catch (const std::exception &e) { 
        emit SignalPrintingError(QString("Model printing -> ") + e.what()); 
    } catch (...) { 
        emit SignalPrintingError("Unknown error while printing."); 
    } 
} 

// mainwindow.h
class MainWindow : public QMainWindow { 
    ...
    public:
        MainWindow(QWidget* parent = nullptr);
    public slots: 
        void ErrorOccured(const QString& message); 
    ...
}; 

// mainwindow.cpp
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow){
  OpenGLSetting();
  ui->setupUi(this);
  if (!ui->mv_widget) ErrorOccured("Model View Widget creation issue!");

  connect(ui->mv_widget, &gui::ModelViewer::SignalPrintingError, this,&gui::MainWindow::ErrorOccured);
}

void MainWindow::ErrorOccured(const QString& message) { 
    TextMessageOutput("ERROR! " + message); 
}
```

## Pop-up message
A massage that opens in separate window. Is part of `#include <QMessagaBox>`:
```C++
// mainwindow.cpp
void MainWindow::PopupMessageOutput(const QString& title_, const QString& text_) {
  QMessageBox::information(this, title_, text_);
}
```

## File dialog
A separate window (modal dialog) that lets the user choose a file path to save something / open something etc.

### Structure
- `const QString &filter` - list of types and their names that will be supported as filters in the new window.

#### Save file dialog
```C++
QString QFileDialog::getSaveFileName(
        QWidget *parent = nullptr,
        const QString &caption = QString(),
        const QString &dir = QString(),
        const QString &filter = QString(),
        QString *selectedFilter = nullptr,
        Options options = Options()
);
```

#### Open file dialog
```C++
QString variable = QFileDialog::getOpenFileName(
        QWidget *parent,
        const QString &caption,
        const QString &directory,
        const QString &filter,
        QString *selectedFilter = nullptr,
        QFileDialog::Options options = QFileDialog::Options()
);
```

### Example
#### Save file dialog
```C++
std::string file = QFileDialog::getSaveFileName( 
    this, 
    tr("Save image"),                                                   // dialog window title
    "/images/new_image.png",                                            // directory/filename
    "PNG Files (*.png);;JPEG Files (*.jpg *.jpeg);;BMP Files (*.bmp)"   // filte list
    ).toStdString();
```

#### Open file dialog
```C++
QString new_file_name = QFileDialog::getOpenFileName(
    this, 
    tr("Choose object file"),       // dialog window title
    m_file_name,                    // directory/filename
    tr("Object files (*.obj)")      // filte list  
    );
```

## Color dialog
It opens a color-picker dialog (separate window) and returns the color the user selects.

### Structure
```C++
QColor QColorDialog::getColor(
        const QColor &initial,
        QWidget *parent = nullptr,
        const QString &title = QString(),
        QColorDialog::ColorDialogOptions options = ColorDialogOptions()
);
```

### Example
```C++
QColor new_color = QColorDialog::getColor(
        ui->mv_widget->GetModelColor(),   // initial color
        this,                             // parent widget
        tr("Choose model color:")         // dialog title
);
```


## Multithreading 
Multithreading is a method of moving time/resource-taking actions to second/third etc. thread so that tasks will be executed parallelly. 
In Qt threads are handled by `#include <QThread>` with support for signals/slots and `QObject`.

### Example
```C++
// model_parcer_worker.h 
namespace controller {
class ModelParserWorker : public QObject {
  Q_OBJECT

 public:
  explicit ModelParserWorker(const QString& filename_, QObject* parent_ = nullptr): QObject(parent_), m_filename(filename_) {}
 signals:
  void finished(std::shared_ptr<inbound_model::Model3D> model);
  void error(const QString& message);
 public slots:
  void Process(){
    using inbound_model::Model3D;
    try {
        std::unique_ptr<Model3D> model =
            inbound_model::ParseModelFromFile(m_filename.toStdString());
        emit finished(std::shared_ptr<Model3D>(std::move(model)));
    } catch (const std::exception& e) {
        emit error(QString::fromStdString(e.what()));
    }
    }

 private:
  QString m_filename;
};
}  // namespace controller

// mainwindow.cpp
void MainWindow::on_bt_show_model_clicked() {
  using controller::ModelParserWorker;
  using inbound_model::Model3D;

  auto worker = new ModelParserWorker(m_file_name);
  QThread* thread = new QThread;

  worker->moveToThread(thread);
  connect(thread, &QThread::started, worker, &ModelParserWorker::Process);

  connect(
      worker, &ModelParserWorker::finished, this,
      [this, thread, worker](std::shared_ptr<Model3D> model) {
        thread->quit();
        thread->wait();
        worker->deleteLater();
        thread->deleteLater();
        try {
          ui->mv_widget->SetModel(std::move(model));
          ModelDataOutput();
        } catch (const std::exception& e) {
          ErrorOccured("Model not set: " + QString::fromStdString(e.what()));
        }
        ChangeModel([this] { ui->mv_widget->update(); });
      });
  connect(worker, &ModelParserWorker::error, this,
          [this](const QString& msg) { ErrorOccured("Not Parsed: " + msg); });
  TextMessageOutput("Model is loading");
  thread->start();
}
```

## Mouse tracking
Qt allows mouse actions (inc. moving) tracking with `#include <QMouseEvent>`

### Example
    [Viewer3D/view/gui/model_viewer/mose_actions.h](https://github.com/Georgiy-JO/Viewer3D)

## 3D graphic
Qt has instruments to show and work with 3D objects. 
Qt supports several instruments like:
|Name|Description|Purpose / Note|
|---|---|---|
|**Qt 3D Module**|High-level, scene-graph-based 3D engine|A full 3D engine built into Qt|
|**Qt Quick 3D**|QML-based high-level 3D engine|3D in QML (declarative UI)|
|**Qt Multimedia + Qt 3D Animation**|Extra tools for animated models|Skeletal animation,keyframe animations|
|**QOpenGLWidget / QOpenGLFunctions / QOpenGLFunctions_3_3_Core**|Raw/OpenGL-level rendering| Manual 3D rendering using pure OpenGL (build in OpenGL support) |
|**Qt OpenGL Module**|`QGLWidget` (old version of `QOpenGLWidget`)|Deprecated in newer Qt versions, but still available|

* Qt has `#include <QOpenGLShaderProgram>` that allows not only working with OpenGL, but use GPU and ***Shaders*** for faster calculations.

### Example
#### [OpenGL + Shaders](https://github.com/Georgiy-JO/Viewer3D)





