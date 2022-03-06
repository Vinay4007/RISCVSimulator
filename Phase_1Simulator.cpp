#include <iostream>
using namespace std;

// Everything in the memory will be stroed in hexadecimal system
char memory[5000] = {'0'};

int mem_pointer = 0;

uint32_t R[32];

string filename;

ifstream in_data;
ifstream in_filename;

class Execution
{

public:
    stack<string> string_memory;
    stack<string> label;
    stack<string> label_data;
    stack<int> int_memory;
    stack<int> data_int;
    stack<int> data_str;

    bool isByte(int i)
    {
        if (i % 4 == 0)
            return true;
        else
            return false;
    }

    int load_word(char ch[])
    {

        int l = strlen(ch);
        int t = MAth.pow(16, l - 1);
        int decimal_form = 0;

        for (int i = 0; i < l; i++)
        {

            if (ch[i] >= '0' && ch[i] <= '9')
            {
                decimal_form += (ch[i] - 48) * t;
                t = t / 16;
            }
            else if (ch[i] >= 'A' && ch[i] <= 'F')
            {
                decimal_form += (ch[i] - 55) * t;
                t = t / 16;
            }
        }

        return decimal_form;
    }

    bool is_word(string st){

        int l=st.length();
        for(int i=0;i<l;i++){

            if(st[i]>=0 || st[i]<=9){
                return false;
            }
        }
        return true;
    }

    void store_word(int n)
    {

        char hexadecimal_form[4];
        int count = 0;

        while (n != 0)
        {

            int rem = n % 16;

            if (rem < 10)
            {

                hexadecimal_form[count++] = rem + 48;
            }

            else
            {

                hexadecimal_form[count++] = rem + 55;
            }

            n = n / 16;
        }

        if (count == 1)
        {
            memory[mem_pointer] = hexadecimal_form[i - 1];
            mem_pointer = mem_pointer + 4;
        }
        else if (i == 2)
        {
            memory[mem_pointer + 1] = hexadecimal_form[i - 1];
            memory[mem_pointer] = hexadecimal_form[i - 2];
            mem_pointer = mem_pointer + 4;
        }
        else if (i == 3)
        {
            memory[mem_pointer + 2] = hexadecimal_form[i - 1];
            memory[mem_pointer + 1] = hexadecimal_form[i - 2];
            memory[mem_pointer] = hexadecimal_form[i - 3];
            mem_pointer = mem_pointer + 4;
        }
        else if (i == 4)
        {
            memory[mem_pointer + 3] = hexadecimal_form[i - 1];
            memory[mem_pointer + 2] = hexadecimal_form[i - 2];
            memory[mem_pointer + 1] = hexadecimal_form[i - 3];
            memory[mem_pointer] = hexadecimal_form[i - 4];
            mem_pointer = mem_pointer + 4;
        }
    }

    void store_word(int n, int address)
    {

        char hexadecimal_form[4];
        int count = 0;

        while (n != 0)
        {

            int rem = n % 16;

            if (rem < 10)
            {

                hexadecimal_form[count++] = rem + 48;
            }

            else
            {

                hexadecimal_form[count++] = rem + 55;
            }

            n = n / 16;
        }

        if (count == 1)
        {
            memory[address] = hexadecimal_form[i - 1];
            address = address + 4;
        }
        else if (i == 2)
        {
            memory[address + 1] = hexadecimal_form[i - 1];
            memory[address] = hexadecimal_form[i - 2];
            address = address + 4;
        }
        else if (i == 3)
        {
            memory[address + 2] = hexadecimal_form[i - 1];
            memory[address + 1] = hexadecimal_form[i - 2];
            memory[address] = hexadecimal_form[i - 3];
            address = address + 4;
        }
        else if (i == 4)
        {
            memory[address + 3] = hexadecimal_form[i - 1];
            memory[address + 2] = hexadecimal_form[i - 2];
            memory[address + 1] = hexadecimal_form[i - 3];
            memory[address] = hexadecimal_form[i - 4];
            address = address + 4;
        }
    }

    void read_data(string filename, string data, string text)
    {

        ifstream in_memory;

        in_memory.open(filename);

        string str1 = "";
        string str2 = "";
        string op_word = "";

        while (in_memory)
        {

            while (str1 != data)
            {
                getline(in_memory, str1);
            }
            getline(in_memory, str2) :

                                       if (str2 == text)
            {
                in_memory.close();
            }
            else
            {
                char ch[ste.length()];

                for (inti = 0; i < l - 1; i++)
                {
                    c[i] = str2[i];
                }

                while (c[i] != ' ')
                {

                    if (i >= l)
                    {
                        break;
                    }

                    op_word += c[i++];
                }

                if (c[i + 1] == ' ')
                {

                    if (op_word != "")
                    {

                        int size = word.length();
                        if (word[size - 1] == ":")
                        {

                            string st = "";
                            for (int i = 0; i < size - 1; i++)
                            {
                                st += word[i];
                            }
                            label_data.push(st);
                            word = "";
                        }

                        else if(is_word(st)){

                            label_data.push(st);
                            word="";
                        }

                        else{

                            stringstream ss(word);
                            int i;
                            ss>>i;
                            data_int.push(i);
                            word="";
                        }
                    }
                }

                while (!data_int.empty())
                {

                    if (label_data.top() == ".word")
                    {
                        if (flag == 0)
                        {

                            int size = data_int.size();
                            index1 = index1 + 4 * size - 1;
                            flag++;
                        }
                        decToHexa(data_int.top());
                        data_int.pop();
                    }
                }
            }
        }
    }
}


class Parser
{
    Execution obj;

public:
    // reads the file line by line
    void parser(string s, int n)
    {
        obj.parse_data(fName, ".data", ".text");
        string line;
        string l1;

        if (n >= 5)
        {
            if ((s[n - 4] == '.' && s[n - 3] == 'a' && s[n - 2] == 's' && s[n - 1] == 'm') || (s[n - 2] == '.' && s[n - 1] == 's'))
            {
                in.open(s);

                while (in)
                {
                    while (l1 != "main:")
                    {
                        getline(in, l1);
                    }
                    getline(in, line);
                    if (line == "exit,")
                        in.close();
                    else
                        obj.Inst(line);
                }
                print();
                // in.close();
            }
            else
                cout << "Not an assembly language !!" << endl;
        }
        else if (n >= 3)
        {
            if ((s[n - 2] == '.' && s[n - 1] == 'a') || (s[n - 2] == '.' && s[n - 1] == 's'))
            {
                in.open(s);

                while (in)
                {
                    while (l1 != "main:")
                    {
                        getline(in, l1);
                    }
                    getline(in, line);
                    if (line == "exit,")
                    {

                        in.close();
                    }

                    else
                    {
                        obj.Inst(line);
                    }
                }
                print();
            }
            else
                cout << "Not an assembly language !!" << endl;
        }
        else
            cout << "Invalid file :(" << endl;
    }
    // prints the contents of registers and memory
    void print()
    {
        // registers
        for (int i = 0; i < 32; i++)
        {
            if (i >= 0 && i <= 9)
                cout << "R" << i << "    = " << R[i] << endl;
            else
                cout << "R" << (i) << "   = " << R[i] << endl;
        }
        // // Memory
        cout << "Data Segment : " << endl;
        for (int j = 0; j < 4096; j = j + 4)
        {
            cout << "mem[ " << j << " ]  =  0x" << mem[j] << mem[j + 1] << mem[j + 2] << mem[j + 3] << "\t\t ";
        }
    }
};


int main()
{
    for (int i = 0; i < 4096; i++)
    {
        mem[i] = '0';
    }
    Parser p;
    cout << "Enter the file name to be opened : ";
    cin >> fName;
    int n = fName.length();

    p.parser(fName, n);

    return 0;
}