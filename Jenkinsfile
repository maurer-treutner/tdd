pipeline{
    agent any

    stages {
        stage('Build')
        {
            steps{
                echo 'Building...'
                sh "md -p build"
                sh "md -p ext/build"
                sh "md -p prefix"
                cmakeBuild([
                    buildDir: 'ext/build',
                    sourceDir: 'ext',
                    cmakeArgs: '-Dprefix',
                    installation: 'cmake in search path'
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