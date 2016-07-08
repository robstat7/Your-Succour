#include"header.hpp"

int main()
{
    fstream fo("rawdata.dat",ios::in|ios::out);
    fstream det("detail.dat",ios::in|ios::out|ios::app);
    fstream fi("data.dat",ios::in|ios::out|ios::app);

    notify_init("Your Succour");
    time_t t1 = time(0);
    time_t lastTime;
    if(det.tellg()>0)
    {
        det.seekg(0,ios::beg);
        det>>lastTime;
    }    

    while(true)
    {
	// checking for exsisting quotations
	if(fi.tellg()>0)
        { 
	    fi.seekg(0,ios::beg);
	    char word[100];
 	    //skipping multiple quotations in the data.dat file
            srand(0); 
	    int ran=rand()%20;
            for(int i=0;i<=ran;i++)
            fi.getline(word,100);    
            NotifyNotification * n = notify_notification_new ("Your Succour",word,0);
	    notify_notification_set_timeout (n, 15000); //15 sec
	    notify_notification_show(n, 0);
        }

        
	else if (t1-lastTime>86400)
	    {
	        try
	        {
	             // perparing session
	    	     URI uri("http://quotelicious.com/new-quotes");
	             HTTPClientSession session(uri.getHost(), uri.getPort());        

	             // preparing path
	             string path(uri.getPathAndQuery());
	             if (path.empty())
	             path = "/";

	             // send request
	             HTTPRequest req(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
	             session.sendRequest(req);

	             // get response
	             HTTPResponse res;
	             fo << res.getReason() << endl;

	             //save response to rawdata.dat
	             istream &is = session.receiveResponse(res);
	             StreamCopier::copyStream(is, fo);
 	
                     //save date of latest update
                     det.close();
                     det.open("detail.dat",ios::trunc);
                     det<<t1;       

	             // parsing the html page 
	             thread t (parse);
                     t.join();
             }

             catch (Exception &ex)
             {
                 NotifyNotification * n = notify_notification_new ("Your Succour",ex.displayText().c_str(),0);
	         notify_notification_set_timeout (n, 10000); //10 sec
  	         notify_notification_show(n, 0);
	         return -1;
             }
         } //end of else if(t1-lastTime>86400) 

    else   //first time
    {
         try
	        {
	             // perparing session
	    	     URI uri("http://quotelicious.com/new-quotes");
	             HTTPClientSession session(uri.getHost(), uri.getPort());        

	             // preparing path
	             string path(uri.getPathAndQuery());
	             if (path.empty())
	             path = "/";

	             // send request
	             HTTPRequest req(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
	             session.sendRequest(req);

	             // get response
	             HTTPResponse res;
	             fo << res.getReason() << endl;

	             //save response to rawdata.dat
	             istream &is = session.receiveResponse(res);
	             StreamCopier::copyStream(is, fo);
 	
                     //save date of latest update
                     det.close();
                     det.open("detail.dat",ios::trunc);
                     det<<t1;       

	             // parsing the html page 
	             thread t (parse);
                     t.join();
             }

             catch (Exception &ex)
             {
                 NotifyNotification * n = notify_notification_new ("Your Succour",ex.displayText().c_str(),0);
	         notify_notification_set_timeout (n, 10000); //10 sec
  	         notify_notification_show(n, 0);
	         return -1;
             }
    } //end of else

sleep(60);
}

    det.close();
    fi.close();
    fo.close();
    return 0;
} 

