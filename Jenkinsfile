pipeline{
    agent any

    stages {
        stage('Build'){
            steps{
                echo 'Building...'
                sh "cmake --version"
                sg "./build.sh"
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