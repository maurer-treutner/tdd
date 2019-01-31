pipeline{
    agent any

    stages {
        stage('Build')
            def workspace = pwd()
            steps{
                echo 'Building...'
                sh "cmake --version"
                echo '$(workspace)'
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