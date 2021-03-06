#pragma once

#include "libcbs.h"
#include "ICBS_Object.h"

// Event value
typedef enum CBS_SOCKET_EVENT
{
	EVENT_CBS_SOCKET_NONE = 1000,

	EVENT_CBS_SOCKET_CONNECTION_START,		// start to try connection
	EVENT_CBS_SOCKET_CONNECTION_SUCCESS,	// Connection established
	EVENT_CBS_SOCKET_CONNECTION_DROP,		// Connection dropped after connected
	EVENT_CBS_SOCKET_CONNECTION_FAIL,		// Connection failed
	EVENT_CBS_SOCKET_SEND,					// send data
	EVENT_CBS_SOCKET_RECIEVE,				// receive data

	EVENT_CBS_SOCKET_ADD,					// Add socket to SocketManager		(internal)
	EVENT_CBS_SOCKET_REMOVE,				// Remove socket from SocketManager	(internal)

	EVENT_CBS_SOCKET_LAST_EVENT
} CBS_SOCKET_EVENT;

// Socket type
typedef enum CBS_SOCKET_TYPE
{
	SOCKET_NONE,				// not init
	SOCKET_TCPSERVER,			// listner socket for server			(TCP)
	SOCKET_TCPREMOTE,			// connection socket for remove client	(TCP)
	SOCKET_TCPCLIENT,			// connection socket for client			(TCP)
	SOCKET_UDPCLIENT,			// socket for udp client				(UDP)
	SOCKET_UDPSERVER			// listner socket for server			(UDP)
} CBS_SOCKET_TYPE;


class ICBS_SocketEventHandler;
class ICBS_Socket;
class ICBS_Stream;

///////////////////////////////////////////////////////////////////////////////
// socket manager interface
class LIBCBS ICBS_SocketManager : public ICBS_Object
{
public:
	static ICBS_SocketManager*	Create();

	// init, close
	virtual bool			Initialize(ICBS_SocketEventHandler* eventHandler=NULL) = 0;
	virtual void			Uninitialize() = 0;

	// socket management
	virtual int				GetSocketCount() = 0;
	virtual ICBS_Socket*	GetSocket(int i) = 0;
	
	// dispatch message
	virtual void			DispatchEvents() = 0;		// send socket events

	// thread management
	virtual void			Lock() = 0;
	virtual void			Unlock() = 0;

	// tcp
	virtual ICBS_Socket*	StartTCPClient(const char* host, int port, ICBS_Socket* socket=NULL) = 0;	// client for connect
	virtual ICBS_Socket*	StartTCPServer(int port, ICBS_Socket* socket=NULL) = 0;						// server to listen

	// udp
	virtual ICBS_Socket*	StartUDPClient(const char* host, int port, ICBS_Socket* socket=NULL) = 0;	// client for send
	virtual ICBS_Socket*	StartUDPServer(int port, ICBS_Socket* socket=NULL) = 0;						// server for receive
};

///////////////////////////////////////////////////////////////////////////////
// socket interface
class LIBCBS ICBS_Socket : public ICBS_Object
{
public:
	static ICBS_Socket*		Create();

	// socket
	virtual bool 			IsOpen() const = 0;			// Is Socket valid?
	virtual bool 			IsConnected() const = 0;    // Is Socket connected?

	virtual CBS_SOCKET_TYPE	GetType() const = 0;

	virtual uint32			GetFlag() = 0;
	virtual void			SetFlag(uint32 v) = 0;

	virtual void*			GetData() = 0;
	virtual void			SetData(void* v) = 0;

	virtual astring			GetHostName() = 0;
	virtual int				GetHostPort() = 0;

	virtual void			SetSocketBufferSize(int recv, int send) = 0;

	virtual void			Close() = 0;

	// read write
	virtual int				Read(ICBS_Stream* buf) = 0;
	virtual int				Write(ICBS_Stream* buf) = 0;
	virtual int				Write(const void* buf, int size) = 0;

	virtual MTIME			GetLastTime() = 0;
};

///////////////////////////////////////////////////////////////////////////////
// socket event interface
class LIBCBS ICBS_SocketEventHandler : public ICBS_Object
{
public:
	virtual void			OnEvent(ICBS_Socket* sk, CBS_SOCKET_EVENT evt, int wparam, void* lparam) = 0;
	virtual void			OnAddSocket(ICBS_Socket* sk) {}
	virtual void			OnRemoveSocket(ICBS_Socket* sk) {}
};
    ^ǚ�!A������Im���&��|���1qw9]����B� (ȱ:�ΉC�R�e��1��Y�,�S���M��Vs��Ճ��xS�"��߮ͳbB�$�����,��"ϑ�6=��X�G*Y"^"|Qn��6tO8�߸�m
w�V]��'�� �y�<?N�7c�b:(��WmЌ�!��}p�T�