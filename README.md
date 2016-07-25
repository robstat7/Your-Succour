# Your-Succour

Displays famous quotations after every 15 minutes on your Ubuntu desktop. (Requires active internet connection)

![Your-Succour-Screenshot](https://cloud.githubusercontent.com/assets/12946753/16707486/3eff8012-45ed-11e6-8452-a8a97edf4c4d.png)

## Building from the source

### Dependecies
1. Install ```libnotify``` by using the command : ```sudo apt-get install libnotify-dev```
2. Download the POCO library source from [here](http://pocoproject.org/releases/poco-1.7.3/poco-1.7.3.tar.gz)
3. Follow the instructions for Unix/Linux installation being provided in the included README file

### How to build the binary
1. Clone the repository into your local system and move into the directory
2. Type the command in the terminal : ``` g++ -std=c++11 source.cc parse.cc -o Your_Succour -lPocoNet -lPocoFoundation `pkg-config --cflags --libs libnotify````
3. Then add the executable ```Your_Succour``` so created into the ```Startup Applications```.


