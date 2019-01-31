pipeline{
    agent any

    environment{
        workspace = pwd()
        FOO = "foo"
    }

    stages {
        stage('Build')
        {
            steps{
                echo 'Building...'
                sh "cmake --version"
                echo '${FOO}'
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