#include"header.hpp"

void showQuote()
{
    ifstream fi(".data.dat",ios::in|ios::app);
    fi.seekg(0,ios::beg);
    char word[200];
    //skipping multiple quotations in the data.dat file
    srand(time(0)); 
    int ran=rand()%20;
    for(int i=0;i<=ran;i++)
    fi.getline(word,200);    
    NotifyNotification * n = notify_notification_new ("Your Succour",word,0);
    notify_notification_set_timeout (n, 15000); //15 sec
    notify_notification_show(n, 0);
    fi.close();
}



int main()
{
    ofstream fo(".rawdata.dat",ios::out|ios::trunc);

    notify_init("Your Succour");
    
    int counter;

    while(true)
    {
        srand(time(0));
        counter=rand()%300+2;
	    try
	    {
	         // perparing session
                 string url="http://quotelicious.com/new-quotes/page/"+to_string(counter);
	    	 URI uri(url);
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
	         fo << res.getReason() <<endl;

	         // save response to rawdata.dat
	         istream &is = session.receiveResponse(res);
	         StreamCopier::copyStream(is, fo);   

	         // parsing the html page 
	         parse();
                  
                 // now showing the quote of the hour
                 showQuote();
             }

             catch (Exception &ex)
             {
                 NotifyNotification * n = notify_notification_new ("Your Succour",ex.displayText().c_str(),0);
	         notify_notification_set_timeout (n, 10000); //10 sec
  	         notify_notification_show(n, 0);
             }
        
	
         
    sleep(900);
    }

    fo.close();
    return 0;
} 

