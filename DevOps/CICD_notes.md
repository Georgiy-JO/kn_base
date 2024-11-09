# Some CICD connected info
**C**ontinuous **I**ntegration and **C**ontinuous **D**elivery

## Contents
- [[#[Basic info](#links)|Basic info]]
- [[#GitLab-Runner|GitLab-Runner]]
	- [[#GitLab-Runner#Structure steps|Structure steps]]
	- [[#GitLab-Runner#Variables|Variables]]
	- [[#GitLab-Runner#CICD machine|CICD machine]]
		- [[#CICD machine#Prepare the machine|Prepare the machine]]
	- [[#GitLab-Runner#.gitlab-ci.yml file|.gitlab-ci.yml file]]
- [[#GitHub Actions (CICD with GitHub)|GitHub Actions (CICD with GitHub)]]
	- [[#GitHub Actions (CICD with GitHub)#CICD machine|CICD machine]]
		- [[#CICD machine#Using GitHub servers|Using GitHub servers]]
		- [[#CICD machine#Prepare a machine for self-host|Prepare a machine for self-host]]
	- [[#GitHub Actions (CICD with GitHub)#Variables|Variables]]
	- [[#GitHub Actions (CICD with GitHub)#Actions repositories:|Actions repositories:]]
	- [[#GitHub Actions (CICD with GitHub)#GitHub Actions file|GitHub Actions file]]
		- [[#GitHub Actions file#Main file - example 1:|Main file - example 1:]]
		- [[#GitHub Actions file#Main file - example 2:|Main file - example 2:]]
		- [[#GitHub Actions file#Service  actions file|Service  actions file]]
- [[#Links:|Links:]]

## [Basic info](#links)
### Theory
**CI/CD** is a set of principles and practices that enable more frequent and secure deployment of software changes.
* *CI/CD** pipeline - a sequence of actions (scripts) for a particular version of the code in the repository, which is started automatically when changes are made.
#### CI 
 *CI** (Continuous Integration) refers to the integration of individual pieces of application code with each other.

* **CI** normally performs two tasks as described below:
	- BUILD:
		- Checking if the code is being built at all;
		- Prepare the artifacts for the next stages;
	- TEST:
		- Codestyle tests;
		- Unit tests;
		- Integration tests;
		- Other tests you have;
		- Test reports.
#### CD 
*CD** (Continuous Delivery) is a continuous integration extension, as it automatically deploys all code changes to the test and/or production environment after the build stage.

* **CD** can perform the following tasks:
	- PUBLISH (If using a deployment docker):
		- Build container images;
		- Push the images to where they will be taken from for deployment;
	- UPDATE CONFIGS:
		- Update configuration on the machines;
	- DEPLOY STAGING:
		- Deployment of test environment for manual tests, QA, and other non-automated checks;
		- Can be run manually or automatically if CI stages are passed successfully;
	- DEPLOY PRODUCTION:
		- Deploying a new version of the system on "production";
		- This stage better be run manually rather than automatically;
		- If you want, you can set it up for a specific branch of the repository only (master, release, etc.).

### Structure
CICD pipeline stages is prewritten and are activated on prepared machine or docker container by CICD provider.
##  GitLab-Runner
**CICD from GitLab**

- CI/CD pipeline must be written in **.gitlab-ci.yml** file that must be located in the project's main directory.

### Structure steps
1. Push a project to GitLab.
2. Gitlab-Runner automatically start executing pipeline written in *.gitlab-ci.yml* file in your project (execution can be triggered by *push*, by time etc.).
3. Execution of pipeline on prepared machine.
4. Result of any and all steps and output files can be seen on the Gitlab of your project on CICD tab.

### Variables
#### Predefined variables
GitLab CI/CD provides some **predefined** [**variables**](https://docs.gitlab.com/ee/ci/variables/ "https://docs.gitlab.com/ee/ci/variables/") that can be used in your .gitlab-ci.yml file and scripts (ex. to store values you want to re-use), such as:  
- CI_COMMIT_MESSAGE  
- CI_COMMIT_DESCRIPTION  - Message except 1st line  
- CI_COMMIT_BRANCH  
- CI_COMMIT_TITLE  - 1st line of the massege  
- CI_JOB_ID  
- CI_JOB_NAME  
- CI_JOB_STAGE  - The name of the job’s stage 
- CI_JOB_STATUS  - Used with _after_script_. Can be _success_, _failed_, or _canceled_  
- CI_PIPELINE_URL  
- CI_PROJECT_NAME  
- CI_PROJECT_TITLE  - human-readable project name
- CI_PROJECT_VISIBILITY  - internal, private or public  
- CI_REPOSITORY_URL  - usable for _git clone_  
- GITLAB_USER_LOGIN  - the one that started the pipeline
#### Secret variables
GitLab allows to create variables via website this variables ca n store sensitive information because they will not be present in the repository.  But they still can be used in CICD pipeline.

### CICD machine
All the CICD pipeline steps are execute an the device you provide and prepare.
#### Prepare the machine
1. Install the GitLab-Runner
```bash
curl -L "https://packages.gitlab.com/install/repositories/runner/gitlab-runner/script.deb.sh" | sudo bash
sudo apt-get install gitlab-runner -y
```
2. Start GitLab-Runner and set the *URL* and security *TOKEN* (these can be got from the GitLab website)
```bash
sudo gitlab-runner start
sudo gitlab-runner register \
--non-interactive \
--url <repository_URL> \
--registration-token <registration_token>\
--executor "shell" \
--description "CICD"
```
- `--non-interactive` - tells the runner to register in non-interactive mode (it won't prompt the user to enter any information manually);
- --`url "..."` - specifies the URL of the GitLab instance that the runner will connect to. 
- `--registration-token "..."` - provides the registration token that is used to authenticate the runner with the GitLab instance. 
- `--executor "..."` - specifies the executor that the runner will use to run jobs.
- `--description "CICD"` - sets a description for the runner.
3. Check the GitLab-Runner status
```bash
  sudo gitlab-runner status
  sudo gitlab-runner verify
```
* Script to help set up an VM for GitLab runner for C/C++: /DevOps/materials/intercourse

### .gitlab-ci.yml file
[Example](/DevOps/materials/CICD_files/.gitlab-ci.yml):
```yml
# list of stages of pipeline (order matters)
stages:
  - pre-build
  - build
  - pos-build
  - deploy

build-job:
  stage: build
  script:
    - echo "Building the application..."
    - cd src/project_files
    - make all 
    - cd ../..
    - cd ..
  artifacts:
    paths:
      - src/project_files/output
    expire_in: 30 days

integration-test-job:
  stage: pos-build
  script:
    - cd src/project_files
    - chmod 755 output_tests_LINUX.sh
    - ./output_tests_LINUX.sh
  needs:
    - code-style-test-job
    - build-job

deploy:
  stage: deploy
  script:
    - echo "Deploying the application..."
    - ./deployment.sh
  needs:
    - code-style-test-job
    - build-job
    - integration-test-job
  when: manual

after_script:
  - ./src/bot_control.sh

code-style-test-job:
  stage: pre-build
  script:
    - echo "Checking code style ..."
    - cd src/project_files
    - clang-format --style=Google -n *.c *.h 
    - clang-format --style=Google -i *.c *.h 
    - if ! git diff --quiet; then
    -   echo "Code style check failed for cat"
    -   exit 1
    - fi
```
* each `stage` of pipeline goes after previous one
* each `job` of pipeline is executes separately and delete all the files after its execution
* `artifacts` - files to be saved after job execution
* `needs` - organize the pipeline so that one job s can't be done if other jobs fails
* `when` - organize the pipeline so that the job must be manually activated with GitLab website
* `after_script` - can be but in particular job, or exist separately if it must be executed after all jobs

## GitHub Actions (CICD with GitHub)
* Description of commands to run by GitHub Actions should be written in *.yml* file located in your repository in *.github/workflows/* folder. The file can have any name and can be created either manually or by **Actions** tab on your GitHub repository website (this way offers some templates).
* GitHub Actions allow to run pre-written  actions from the [actions repositories](https://github.com/actions) using the following syntax. This "actions" are already written logic that can be used and executed inside you jobs. 

### CICD machine
All the CICD pipeline steps are execute on GitHub servers (Ubuntu/WIN/macOS) or on an the device you provide and prepare. Important to remember that for each job a new github server gets created.
```shell
# github example
runs-on: ubuntu-latest
# self-hosted example
runs-on: self-hosted
```
- If you want to run the same actions on several platforms you can use the following pattern:
```yml
runs-on: ${{matrix.os}}
	matrix:
	  os: [ubuntu-latest, windows-latest, macOS-latest] 
```

#### Using GitHub servers
-
#### Prepare a machine for self-host
* Adding a self-hosted runner requires that you download, configure, and execute the GitHub Actions Runner.
  1. Go to the repository settings on GitHub website and on *actions/runners* settings page press the create self-hosted runner.
  2. Follow the steps from the page: install the GitHub actions at the machine that will host pipelines.
    -  Remember that the token will expire with time. If installation took too much, renew the page with the token.
  3. Run the Action machine only when you are ready for running pipelines.

* Script to help set up an VM for GitHub Actions for C/C++: /DevOps/materials/intercourse

### Variables
#### Secrets and website set variables
- GitHub Actions allows to create secret variables for a project in the *settings* of the repository. These variables won't be present in the repository files, but can be used in Actions.
	- Secret variables can be used like: `${{ secrets.SECRET_VARIABLE_NAME }}`

#### Predefined variables
- `${{ job.status }}` - status of the job.
- `GITHUB_REPOSITORY` - nick of the repository owner and the repository name separated by `/`.
- `GITHUB_JOB` - job name.
- `GITHUB_TRIGGERING_ACTOR` - nick of the user who triggered the GitHub Actions.

### Actions repositories: 
- open source repositories with `action.yml` files available for particular tasks, those can be used in your main actions file as a part of it, to make it simpler to work with an understand.

| Name (`- uses:` )          | Repository                                          | Description                                                                                                                                |
| -------------------------- | --------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| actions/checkout@v4        | [Click](https://github.com/actions/checkout)        | This action checks-out your repository.                                                                                                    |
| actions/upload-artifact@v4 | [Click](https://github.com/actions/upload-artifact) | Upload [Actions Artifacts](https://docs.github.com/en/actions/using-workflows/storing-workflow-data-as-artifacts) from your workflow runs. |

### GitHub Actions file
#### Main file - example 1:
```yml
name: CI example
# Controls when the workflow will run
on:
  push:
    branches: [ "main" ]
  workflow_dispatch:

# A workflow run is made up of one or more jobs that can run sequentially or in parallel
jobs:
  build:
    # The type of runner that the job will run on
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      # Runs a set of commands using the runners shell
      - name: Run a multi-line script
        run: |
          echo Add other actions to build,
          echo test, and deploy your project.
```

* GitHub Actions allows specifying then the pipeline will run in the file  by `on`. There are [several possible events](https://docs.github.com/en/actions/writing-workflows/choosing-when-your-workflow-runs/events-that-trigger-workflows) that may trigger actions.
* `workflow_dispatch` - allows you to run this workflow manually from the Actions tab.
* `steps` - represent a sequence of tasks that will be executed as part of the job
* `uses: actions/checkout@v4` - checks-out your repository under $GITHUB_WORKSPACE, so your job can access it, using an open Actions repository.
* Naming steps is not necessary but can be added no any **step** (including `uses`).
* initial execution take place in the main directory of the project.

#### Main file - example 2:

```yml
name: CI
on:
  push: 
  workflow_dispatch:

jobs:

  valgrind-check:    
    runs-on: self-hosted
    needs: [building-lib-job, testing-job]
    steps:
      - uses: actions/checkout@v4

      - name: C++/C code with Valgrind
        run: |
          cd src
          make valgrind_me
          grep -oPm 1 "ERROR SUMMARY:\s+\K[0-9]+" RESULT_VALGRIND.txt > VAR.txt
          if [ $(grep -oP "[0-9]+" VAR.txt) -ne 0 ]; then 
            echo "$(grep . VAR.txt) error(s)" > VAR.txt
            exit 1
          fi
          echo "" > VAR.txt

      - name: Sending bot message
        if: always()
        uses: ./.github/actions/bot_messaging
        with:
          bot_token: ${{ secrets.BOT_GLADOS_URL }}
          chat_id: ${{ secrets.JO_CHAT_ID }}
          job_status: ${{ job.status }}
        continue-on-error: true

      - name: Upload artifact
        uses: actions/upload-artifact@v4
        if: failure() 
        with:
          name: valgrind-output
          path: src/RESULT_VALGRIND.txt  
          retention-days: 5    

    continue-on-error: true    
```
- `needs`:
	*  **Default Behavior**: By default, jobs in GitHub Actions run in parallel, meaning they do not wait for each other to complete.
	- **Setting Dependencies**: You can control the order of job execution by using the `needs` keyword, which allows you to define dependencies between jobs.
* `if:` specify when the step will be executed (`always()`- does not matter if previous step fail or not, `failure()` - executes only in case of failure, etc)
* `continue-on-error: true`:
	* if used at the step level, will make all following steps continue in case this step fails (! will change the output from failure to success - that will affect the total output of the job (aka. change the job status));
	* if used at the job level, will allow pipeline to continue in case the job fails, but the job status will remain failed and this will be indicated in GitHub Actions.
- `uses:` - allows to integrate into the file other big actions file with whole jobs, smaller files with sets of commands for particular goal, files from open actions repositories (in this example it is an ***action.yml*** file located in *./.github/actions/bot_messaging* folder).
- `with:` - allows to pass variables to executing file.
- `uses: actions/upload-artifact@v4` - github actions public repository to save artifacts.
	- `retention-days:`  - sets the time artifacts will be saved for (can work with dates).
	- `name:` - name of the resulting artifact archive.
	- `path:` - the location of the artifacts folder/file.

#### Service  actions file
- Service files are smaller actions files that can be called and used in main actions file.
- Service files **MUST**  be named ***action.yml***, but can be located in any location in a repository.
```yml
name: 'Bot messaging'
description: 'This action sends CICD job and step info via telegram bot.'

inputs:
  bot_token:
    description: 'Telegram bot API token for url'
    required: true
  chat_id:
    description: 'Telegram chat ID'
    required: true
  job_status:
    description: 'Stores the status of the job'
    required: true

runs:
  using: 'composite'
  steps:
    - name: Creating empty comment file if needed
      shell: bash
      run: echo "" >> src/VAR.txt

    - name: Sending message
      shell: bash
      env:
        BOT_URL_API_TOKEN: ${{ inputs.bot_token }}
        CHAT_ID: ${{ inputs.chat_id }}
        JOB_STATUS: ${{ inputs.job_status }}
      run: sh ./.github/bot_controls.sh
```
- `inputs:` - sets variables that are to be passed to this file on activation (name them, describe them, set if those are required, etc).
- `using: 'composite'` - specifies that the action is using a composite run, allowing multiple steps to be defined within it.
- `shell:` - specifies  the shell used for this step.
- `env:` - creating environmental variables, those can be created:
	- at the whole *.yaml* file level - this way those are global and can be used in all jobs.
	- at the job level (inside a job) - those cat be used inside a job in all steps (and script files).
	- at the step level - variables only for this particular step.

## Links:
* Example of CICD
  - [GitLab](/DevOps/materials/CICD_files/.gitlab-ci.yml) 
  - [GitHub](/DevOps/materials/CICD_files/.github/workflows/self-host_cicd.yml)
    - [Extra actions file](/DevOps/materials/CICD_files/.github/actions/bot_messaging/action.yml)
* [Step by step practice of GitLab CICD](https://github.com/Georgiy-JO/DO_practice_projects) 
* [Example of using GitLab CICD in a project](https://github.com/Georgiy-JO/the_matrices_C_pet) 
* What is CICD article: 
  - [VID](https://youtu.be/Hkq_78xSfSY?si=lXUiY6rDMs3TQPtA),
  - [RU](https://habr.com/ru/companies/otus/articles/515078/),
  - [EN](https://www.infoworld.com/article/2269266/what-is-cicd-continuous-integration-and-continuous-delivery-explained.html).
* GitHub
  - [Actions repositories](https://github.com/actions)
