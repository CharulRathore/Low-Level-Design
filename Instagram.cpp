/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

class Account {
private:
    stirng uid;
    string password;
    
public:
    bool verify_uid_password();
};

class User_Activity {
private:  
    Post* user_post_head;
    User* user;
    vector<Activity_Log*> logs;
    
public:
    Post* createPost(string post_id, string content, string date) {
        Post* post = new Post(user_id, post_id, content, date);
        post->next = user_post_head->next;
        post->prev = user_post_head;
        user_post_head->next = post;
        post->next->prev = post;
        return post;
    }
    
    Post* getTimeline() {
        return user_post_head;
    }
    
    void changePicture();
    void update_details();
};

class User_Feed {
private:
    User* user;
    Post* feed_head;
    Post* last_feed_post_seen;

public:
    void update_feed(Post* post) {
        // update feed
    }
    
    vector<Post*> view_feed() {
        // by default, show first 20 posts, then after scrolling show 20 more
        int i=0;
        if (last_feed_post_seen == NULL)
            last_feed_post_seen = post_head;
            
        vector<Post*> result;   
        Post* ptr = last_feed_post_seen;
        while (i<20 && ptr->next) {
            ptr = ptr->next;
            last_feed_post_seen = ptr;
            result.push_back(ptr);
            i++;
        }
        return result;
    }
    
    void reset_last_seen_token() {
        last_feed_post_seen = feed_head;
    }
};

class User {
private:
    string name;
    string details;
    Account user_account;
    User_Feed* feed;
    User_Activity* activity;
    vector<User*> following;
    vector<User*> followers;
    
public:
    void followUser(User* user) {
        user->add_followers(this);
    }
    
    void update_feed(Post* post) {
        feed->update_feed(post);
    }
    
    void createPost() {
        Post* post = activity->createPost();
        
        // fanout if num of followers < 400
        for (auto follower : followers) 
            follower->update_feed(post);
    }
    
    bool login() {
        if (!user_account.verify_uid_password())
            return false;
        feed->reset_last_seen_token();
        vector<Post*> posts = feed->view_feed();
        return true;
    } 
    
    vector<Post*> scroll() {
        return feed->view_feed();
    }
};

int main()
{
    return 0;
}
