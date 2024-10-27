# Some CICD connected info
**C**ontinuous **I**ntegration and **C**ontinuous **D**elivery
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

### .gitlab-ci.yml file
Example:
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

## CICD with GitHub




## Links:
* [Example of GitLab CICD](https://github.com/Georgiy-JO/DO_practice_projects) 
* [Example of using GitLab CICD of a project](https://github.com/Georgiy-JO/the_matrices_C_pet) 
* What is CICD article: [VID](https://youtu.be/Hkq_78xSfSY?si=lXUiY6rDMs3TQPtA),[RU](https://habr.com/ru/companies/otus/articles/515078/),[EN](https://www.infoworld.com/article/2269266/what-is-cicd-continuous-integration-and-continuous-delivery-explained.html).
