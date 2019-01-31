pipeline{
    agent any

    stages {
        stage('Build'){
            steps{
                echo 'Building...'
                sh "cmake --version"
                sh "echo $(pwd)"
            }
        }
        stage('Test')
        {
            steps{
                echo 'Testing...'
            }
        }
        stage('Deploy')
        {
            steps{
                echo 'Depoloying...'
            }
        }
    }
}