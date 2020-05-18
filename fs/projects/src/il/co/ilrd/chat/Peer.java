package il.co.ilrd.chat;

import java.util.Set;

public interface Peer {
	
	public void responseMessage(int msgID, int userID, String userName, String groupName, UserProperties prop, String message, ChatResponsStatus status);
	public void responseJoinGroup(int msgID, int userID, String userName, String groupName, ChatResponsStatus status);
	public void responseLogin(int msgID, int userID, Set<String> groupNames,  ChatResponsStatus status);
	public void responseCreateGroup(int msgID, String groupName,  ChatResponsStatus status);
	public void responseLeaveGroup(int msgID, int userID, String userName, String groupName, ChatResponsStatus status);
}

