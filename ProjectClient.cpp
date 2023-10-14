static int port = 2242;

ProjectClient::ProjectClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProjectClient)
{
    ui->setupUi(this);
    
    _socket.connectToHost(QHostAddress::LocalHost, port);  //QHostAddress::Any QHostAddress("192.168.1.3")
    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(_socket, &QTcpSocket::disconnected, this, &ProjectClient::onServerDisconnection);
    connect(_socket, &QTcpSocket::connected, this, &ProjectClient::onServerConnected);
    
    
    //connection retry//
    
    retryServer = new QTimer(this); //take QTimer *retryServer; at the header file
    connect(retryServer, &QTimer::timeout, this, &MainWindow::onServerDisconnection);
    
    
    //write to connected server example//
    QString command = "GoAhead";
    _socket->write(command.toUtf8());
    _socket->waitForBytesWritten();
    _socket->flush();
    
}

void MainWindow::onReadyRead() //take the slot at the header file
{
	QByteArray data_tmp;
	data_tmp = _buttonsock->readAll();
    	qDebug() << "data received from server--> "<<data_tmp;
}

void MainWindow::onServerDisconnection(){
    retryServer->start(60000);
}

void MainWindow::onServerConnected(){
    retryServer->stop();
}
