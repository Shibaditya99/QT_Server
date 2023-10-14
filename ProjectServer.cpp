static int port = 2242;

ProjectServer::ProjectServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProjectServer)
{
    ui->setupUi(this);
    
    if(!_server->listen(QHostAddress::LocalHost, port)) //QHostAddress::Any QHostAddress("192.168.1.3")
            {
                qCritical() << "Server could not start!";
            }
            else
            {
                qInfo() << "Server started at Localhost, "<<port;

            }
            
    connect(_server, &QTcpServer::newConnection, this, &svdgs_op::Client_connection);
    //write to connected client example//
    QString command = "GoAhead";
    _buttonsock->write(command.toUtf8());
    _buttonsock->waitForBytesWritten();
    _buttonsock->flush();
    
}

void ProjectServer::Client_connection(){
    _buttonsock = _server->nextPendingConnection();
    connect(_buttonsock,&QTcpSocket::readyRead,this,&svdgs_op::socketRead);
}

void ProjectServer::socketRead(){
	QByteArray data_tmp;
	data_tmp = _buttonsock->readAll();
    	qDebug() << "data received from server--> "<<data_tmp;

}

