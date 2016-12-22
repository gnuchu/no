#!groovy

node {
  stage('Build') {
    sh 'make'
  }
  stage('Package') {
    sh 'make package'
  }
}