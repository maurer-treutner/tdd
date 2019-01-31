pipeline{
    agent any

    stages {
        stage('Build'){
            steps{
                echo 'Building...'
                cmake --version
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