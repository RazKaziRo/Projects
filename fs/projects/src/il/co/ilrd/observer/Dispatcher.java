package il.co.ilrd.observer;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.function.Consumer;

public class Dispatcher<T> {
	
	private List<Callback<T>> callbackList = new LinkedList<>();
	
	public void register(Callback<T> cb) {
		cb.dispatcher = this;
		callbackList.add(cb);
		}
	
	public void stopAll() {
		
		for(Callback<T> cb : callbackList) {
			cb.notifyDeath();
		}
		callbackList.clear();
	}
	
	public void updateAll(T msg) {
		for(Callback<T> cb : callbackList) {
			cb.update(msg);
		}
	}

	
	public static class Callback <T>{
		
		private Consumer<T> c;
		private Runnable r;
		Dispatcher<T> dispatcher;
		
		public Callback(Consumer<T> c, Runnable r) {
			this.c = c;
			this.r = r;
		}
		
		private void update(T t) {
			c.accept(t);
		}	
		
		private void notifyDeath() {
			r.run();
			dispatcher = null;
		}
		
		public void stopService() {
			dispatcher.callbackList.remove(this);
		}
	}	
}
