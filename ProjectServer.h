//You can Add the necessary libraries//

#include <QMainWindow>
#include <QPushButton>
#include<QDialogButtonBox>
#include <QRadioButton>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QLabel>
#include <QFont>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QSocketNotifier>//Added for GPIO
#include <QStringList>
#include <QGroupBox>
#include <QLabel>
#include <QFont>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QSocketNotifier>//Added for GPIO
#include <QStringList>
#include <QGroupBox>
#include<QTcpServer>
#include<QTcpSocket>
#include<string>
#include<QDateTime>
#include<QtSql/QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QLineEdit>
#include<QTimer>
#include<QSettings>
#include<QApplication>
#include<QMessageLogger>
#include<QtGlobal>
#include<QFile>
#include<QComboBox>


namespace Ui { class ProjectServer; }
QT_END_NAMESPACE

class ProjectServer : public QMainWindow
{
    Q_OBJECT

public:
    ProjectServer(QWidget *parent = nullptr);
    ~ProjectServer();
    
    QTcpServer *_server;
    QTcpSocket *_buttonsock;
    
public slots:
    void Client_connection();
    void socketRead();
    
private:
    Ui::ProjectServer *ui;
    
};
#endif // PROJECTSERVER_H
