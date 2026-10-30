# include <iostream>
#include <string>
using namespace std;

// static array implementation
class Stack{
    private:
        string arr[1000];
        
    public:    
        int size = 0;
        Stack(){
            this->size = 0;
        }
        string top(){
            if (size > 0) return arr[size-1];
            else return NULL;
        }

        void push(string n){
            if (size < 1000) {
                size++;
                arr[size-1] = n;
            }
        }

        void pop(){
            if (size > 0){
                size--;
            }
        }

        // extra memeber functions
        bool is_full(){
            return this->size == 1000;
        }

        bool is_empty(){
            return size == 0;
        }

        bool is_equal(Stack second){
            Stack first = *this;  //cloning the object to freely edit its content for equality logic
            if(first.size == second.size){
                while(first.is_empty() && second.is_empty()){
                    if(first.top() != second.top()) break;
                    first.pop();
                    second.pop();
                }
            }
            return first.is_empty() && second.is_empty();
        }
};

bool XML_checker(string XML){
    Stack tag;
    for(int i = 0; i < XML.size(); i++){
        if(XML[i] == '<' && XML[i+1 != XML.size()]){
            bool is_closing = XML[i+1] == '/'? true : false;

            string tag_name;
            if(is_closing){
                i += 2;
                while(XML[i] != '>'){
                    tag_name += XML[i];
                    i++;
                }
                if(tag.top() == tag_name) {
                    tag.pop();
                    cout << "|>--" << tag_name << endl;
                }
                else return false;
            }
            else{
                i += 1;
                while(XML[i] != '>'){
                    tag_name += XML[i];
                    i++;
                }
                tag.push(tag_name);
                cout << tag_name << endl;
            }
        }
    }
    return tag.is_empty();
}

int main(){
    // XML consistency_checker implementation using stack
    string XML = "<breakfast_menu><food><name>Belgian Waffles</name><price>$5.95</price><description>Two of our famous Belgian Waffles with plenty of real maple syrup</description><calories>650</calories></food><food><name>Strawberry Belgian Waffles</name><price>$7.95</price><description>Light Belgian waffles covered with strawberries and whipped cream</description><calories>900</calories></food><food><name>Berry-Berry Belgian Waffles</name><price>$8.95</price><description>Belgian waffles covered with assorted fresh berries and whipped cream</description><calories>900</calories></food><food><name>French Toast</name><price>$4.50</price><description>Thick slices made from our homemade sourdough bread</description><calories>600</calories></food><food><name>Homestyle Breakfast</name><price>$6.95</price><description>Two eggs, bacon or sausage, toast, and our ever-popular hash browns</description><calories>950</calories></food></breakfast_menu>";
    XML_checker(XML)? cout << "valid XML file" << endl : cout << "recheck the file, error were encountered" << endl;

    return 0;
}