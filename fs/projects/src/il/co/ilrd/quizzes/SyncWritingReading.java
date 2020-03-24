package il.co.ilrd.quizzes;

import java.util.concurrent.locks.Lock;

public class SyncWritingReading {
	
    private final Lock lock;    
    private volatile int cnt = 0;
    
    SyncWritingReading(Lock lock){
        this.lock = lock;
    }
    
    public void StartWrite() {
        lock.lock();
        while(cnt > 0) {};

    }
    
    public void EndWrite() {
        lock.unlock();
    }
    
    public void StartRead() {
        lock.lock();
        ++cnt;
        lock.unlock();
    }
    
    public void EndRead() {
        --cnt;
    }
}

