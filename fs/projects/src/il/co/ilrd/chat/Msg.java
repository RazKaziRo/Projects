package il.co.ilrd.chat;

import java.io.Serializable;
import java.util.List;

import il.co.ilrd.chat.ChatClient.RequestHandler;
import il.co.ilrd.chat.TCPCommunication.ResponseHanlder;

public class Msg implements Serializable {
		/**
		 * 
		 */
		private static final long serialVersionUID = -9094319427169171676L;
		private static int msgIdCounter = 0;
		private int msgID;

		public Msg() {
			msgID = ++msgIdCounter;
		}
		
		public Msg(int requestMsgID) {
		   	this.msgID = requestMsgID;
		}
		
		public int getMsgID() {
			return msgID;
		}

	}

	class Request extends Msg{
		
		RequestHandler opID;
	
		private static final long serialVersionUID = 1L;

		public Request(RequestHandler opID) {
	       this.opID = opID;
	    }

		public RequestHandler getOpID() {
			return opID;
		}
		
		
	}

	class Response extends Msg{
		
		ResponseHanlder opID;
		
		private static final long serialVersionUID = 1L;
		private ChatResponsStatus status;
	    
	    public Response(ResponseHanlder opId, int requestMsgID, ChatResponsStatus status) {
	        super(requestMsgID);
	        this.status = status;
	        this.opID = opId;
	    }
	    
	    public ChatResponsStatus getStatus() {
	        return status;
	    }
	}

	class RequestLogin extends Request {
		
		
		private static final long serialVersionUID = -2309362424242713828L;
		private String email;
		private String userName;
		RequestHandler opID;

		public RequestLogin(RequestHandler opId, String email, String userName) {
			super(opId);
			this.email = email;
			this.userName = userName;
		}
		
		public String getEmail() {
			return email;
		}

		public String getUserName() {
			return userName;
		}
	}
		
	class RequestJoinGroup extends Request {
		/**
		 * 
		 */
		private static final long serialVersionUID = -6996446904646899058L;
		private int userId;
		private String groupName;
		
		public RequestJoinGroup(RequestHandler opId, int userId, String groupName) {
			super(opId);
			this.userId = userId;
			this.groupName = groupName;
		}
		
		public int getUserId() {
			return userId;
		}

		public String getGroupName() {
			return groupName;
		}
	}

	class RequestCreateGroup extends Request {
		/**
		 * 
		 */
		private static final long serialVersionUID = -63878996156234175L;
		private int userId;
		private String groupName;
		
		public RequestCreateGroup(RequestHandler opId, int userId, String groupName) {
			super(opId);
			this.userId = userId;
			this.groupName = groupName;
		}
		
		public int getUserId() {
			return userId;
		}
		
		public String getGroupName() {
			return groupName;
		}
	}

	class RequestLeaveGroup extends Request {

		private static final long serialVersionUID = -2400967658850667596L;
		private int userId;
		private String groupName;
		
		public RequestLeaveGroup(RequestHandler opId, int userId, String groupName) {
			super(opId);
			this.userId = userId;
			this.groupName = groupName;
		}
		
		public int getUserId() {
			return userId;
		}
		
		public String getGroupName() {
			return groupName;
		}
	}

	class RequestSend extends Request {
		/**
		 * 
		 */
		private static final long serialVersionUID = -4038599863487136690L;
		private int userId;
		private String groupName;
		private String msg;
		
		public RequestSend(RequestHandler opId, int userId, String groupName, String msg) {
			super(opId);
			this.userId = userId;
			this.groupName = groupName;
			this.msg = msg;
		}

		public int getUserId() {
			return userId;
		}

		public String getGroupName() {
			return groupName;
		}

		public String getMsg() {
			return msg;
		}
	}

	class ResponseLogin extends Response {
		/**
		 * 
		 */
		private static final long serialVersionUID = -5773082868149152439L;
		private int userId;
		private List<String> groups;
		
		public ResponseLogin(ResponseHanlder opId, int requestMsgID, ChatResponsStatus status, int userId, List<String> groups) {
			super(opId, requestMsgID, status);
			this.userId = userId;
			this.groups = groups;
		}

		public int getUserId() {
			return userId;
		}

		public List<String> getGroups() {
			return groups;
		}
	}

	class ResponseJoinGroup extends Response {
		/**
		 * 
		 */
		private static final long serialVersionUID = 740161959953103624L;
		private int userId;
		private String groupName;
		private String senderName;
		
		public ResponseJoinGroup(ResponseHanlder opId, int requestMsgID, ChatResponsStatus status, int userId, String groupName, String senderName) {
			super(opId, requestMsgID, status);
			this.userId = userId;
			this.groupName = groupName;
			this.senderName = senderName;
		}

		public int getUserId() {
			return userId;
		}

		public String getGroupName() {
			return groupName;
		}
		public String getSenderName() {
		    return senderName;
		}
	}

	class ResponseCreateGroup extends Response {
		/**
		 * 
		 */
		private static final long serialVersionUID = -838016303129502199L;
		private int userId;
		private String groupName;
		
		public ResponseCreateGroup(ResponseHanlder opId, int requestMsgID, ChatResponsStatus status, int userId, String groupName) {
			super(opId, requestMsgID, status);
			this.userId = userId;
			this.groupName = groupName;
		}

		public int getUserId() {
			return userId;
		}

		public String getGroupName() {
			return groupName;
		}

	}

	class ResponseLeaveGroup extends Response {
		/**
		 * 
		 */
		private static final long serialVersionUID = -246542286706772128L;
		private int userId;
		private String groupName;
		private String senderName;
		
		public ResponseLeaveGroup(ResponseHanlder opId, int requestMsgID, ChatResponsStatus status, int userId, String groupName, String senderName) {
			super(opId, requestMsgID, status);
			this.userId = userId;
			this.groupName = groupName;
			this.senderName = senderName;
		}

		public int getUserId() {
			return userId;
		}

		public String getGroupName() {
			return groupName;
		}
		
		public String getSenderName() {
		    return senderName;
		}
	} 

	class ResponseSend extends Response {
		
		/**
		 * 
		 */
		private static final long serialVersionUID = -8256573155482333074L;
		private int userId;
		private String groupName;
		private String msg;
		private String senderName;
		private UserProperties prop;
		
		public ResponseSend(ResponseHanlder opId, int requestMsgID, ChatResponsStatus status, int userId, String groupName, String msg, String senderName, UserProperties prop) {
			super(opId, requestMsgID, status);
			this.userId = userId;
			this.groupName = groupName;
			this.msg = msg;
			this.senderName = senderName;
			this.prop = prop;
		}
		public int getUserId() {
			return userId;
		}
		public String getGroupName() {
			return groupName;
		}
		public String getMsg() {
			return msg;
		}
		public String getSenderName() {
			return senderName;
		}
		public UserProperties getProp() {
		    return prop;
		}
	}
