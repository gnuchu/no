#!groovy

node {
  def myVal = "Hello, World!"
  sh "Value of myVal is: ${myVal}"


  stage('Build') {
    checkout scm
    sh 'make'
    input message: 'OK to proceed?', submitter: 'admin'
  }
  stage('Test') {
    echo 'Still got #TODO the tests.'
    input message: 'OK to proceed?', submitter: 'admin'
  }
  stage('Package') {
    checkout scm
    sh 'make package'
    archiveArtifacts artifacts:'build/no-package.tgz'
  }
}