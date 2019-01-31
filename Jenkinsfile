pipeline{
    agent any

    stages {
        stage('Build'){
            steps{
                echo 'Building...'
                sh "cmake --version"
                sh "pwd" 
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