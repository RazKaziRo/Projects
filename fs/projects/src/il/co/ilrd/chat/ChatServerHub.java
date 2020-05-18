package il.co.ilrd.chat;

import java.awt.Color;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import il.co.ilrd.collections.HashMap;

public class ChatServerHub implements ChatServer{
	
	private Map<Integer, User> users = new HashMap<>();
	private Map<Integer, Group> groups = new HashMap<>();
	private static int users_counter = 0;
	private static int groups_counter = 0;

	@Override
	public void logIn(String email, String name, Peer p) {
		
		User user;
		
		if((user = getUserByEmail(email)) == null) {
			user = new User(name, email, p);
			users.put(user.getId(), user);
		}
		
		//send to peer logi

	}
	
	private User getUserByEmail(String email) {
		for(Entry<Integer, User> user : users.entrySet()) {
			if(user.getValue().getEmail().equals(email)) {
				return user.getValue();
			}
		}
		return null;
	}

	@Override
	public void createNewGroup(Integer userId, String groupName) {
		
	}

	@Override
	public void joinGroup(Integer userId, Integer groupId) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void leaveGroup(Integer userId, Integer groupId) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void sendMsg(Integer userId, Integer groupId, String msg) {
		// TODO Auto-generated method stub
		
	}
	
	private static class User {
		
		private String name;
		private String email;
		private int id;
		private Peer peer;
		private List <Integer> userGroups;
		
		public User(String name, String email, Peer peer) {
			this.name = name;
			this.email = email;
			this.id = ++users_counter;
			this.peer = peer;
			userGroups = new ArrayList<Integer>();
		}

		public String getName() {
			return name;
		}

		public String getEmail() {
			return email;
		}

		private int getId() {
			return id;
		}

		private Peer getPeer() {
			return peer;
		}
		
		private  List<Integer> getUserGroups() {
			return userGroups;
		}
		
		
	}
	
	private static class Group {
		Map<Integer, UserProperties> users;
		Integer groupId;
		
		public Group() {
			this.groupId = ++groups_counter;
			
		}
		private int getGroupId() {
			return groupId;
		}
	
	}
	
	private static class ColorUserProperties implements UserProperties{
		Color color;
	}
}