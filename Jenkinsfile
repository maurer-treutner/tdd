pipeline{
    agent any

    stages {
        stage('Build')
        {
            steps{
                echo 'Building...'
                sh 'mkdir -p build'
                sh 'mkdir -p ext/build'
                sh 'mkdir -p prefix'
                cmake([
                    installation: "Default",
                    workingDir: "ext/build",
                    arguments: "-DINSTALL_PATH=../../prefix .."
                ])
                cmake([
                    installation: "Default",
                    workingDir: "ext/Build",
                    arguments: "--build ."
                ])
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