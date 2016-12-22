#!groovy

node {
  stage('Build') {
    checkout scm
    sh 'make'
  }
  stage('Package') {
    checkout scm
    sh 'make package'
  }
}