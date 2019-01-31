pipeline{
    agent any

    stages {
        stage('Build_Ext')
        {
            steps{
                echo 'Building Externals'
                sh "./build_ext.sh"
            }
        }
        stage('Build')
        {
            steps{
                echo 'Building Project'
                sh "./build_dev.sh"
            }
        }
        stage('Test')
        {
            steps{
                echo 'Testing...'
                ctest([
                    installation:'Default',
                    workingDir:'build'
                ])
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