pipeline{
    agent any

    environment{
        workspace = pwd()
    }

    stages {
        stage('Build')
        {
            steps{
                echo 'Building...'
                sh "cmake --version"
                echo '${workspace}'
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