#ifndef CONVERSATIONMODEL_H
#define CONVERSATIONMODEL_H

#include <QAbstractListModel>
#include <QDateTime>

typedef struct {
	QString author;
	QString recipient;
	QDateTime timestamp;
	QString content;
} Message;

class ConversationModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(QString recipient READ recipient WRITE setRecipient NOTIFY recipientChanged)

	QString _recipient;
	QList<Message> _messages;

public:
	explicit ConversationModel(QObject *parent = nullptr);

	enum {
		AuthorRole = Qt::UserRole,
		RecipientRole,
		TimestampRole,
		ContentRole
	};

	QString recipient() const;

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	 QHash<int, QByteArray> roleNames() const override;

	 Q_INVOKABLE void sendMessage(const QString &recipient, const QString &content);

signals:

	void recipientChanged(QString recipient);

public slots:
	void setRecipient(QString recipient);
};

#endif // CONVERSATIONMODEL_H
