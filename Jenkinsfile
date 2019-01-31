pipeline{
    agent any

    stages {
        stage('Build')
        {
            steps{
                echo 'Building...'
                sh "mkdir -p build"
                sh "mkdir -p ext/build"
                sh "mkdir -p prefix"
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