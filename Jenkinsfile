pipeline{
    agent any

    stages {
        stage('Build')
        {
            steps{
                echo 'Building...'
                sh 'mkdir -pf build'
                sh 'mkdir -pf ext/build'
                sh 'mkdir -pf prefix'
                cmakeBuild([
                    buildDir: 'ext/build',
                    sourceDir: 'ext',
                    cmakeArgs: '-Dprefix',
                    installation: 'Default'
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