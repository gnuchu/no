#!groovy

node {
  stage('Build') {
    checkout scm
    sh 'make'
    input message: 'OK to proceed?', submitter: 'admin'
  }
  stage('Package') {
    checkout scm
    sh 'make package'
    archiveArtifacts artifacts:'build/no-package.tgz'
  }
}