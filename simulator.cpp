#include <bits/stdc++.h>
using namespace std;

// Everything in the memory will be stroed in hexadecimal system
char memory[5000] = {'0'};

int mem_pointer = 0;

int R[32];

string filename;

ifstream in_filename;
ifstream in_function;

class Instruction_mangager
{

public:
    stack<string> ins_string;
    stack<string> label;
    stack<int> ins_int;

    int convert_char_to_decimal(char ch[])
    {

        int l = strlen(ch);
        int t = pow(16, l - 1);
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

    bool is_word(string st)
    {

        int l = st.length();
        for (int i = 0; i < l; i++)
        {

            if (st[i] >= '0' || st[i] <= '9')
            {
                return false;
            }
        }
        return true;
    }

    void store_word_to_memory_address(int n, int address)
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
            memory[address] = hexadecimal_form[count - 1];
            address = address + 4;
        }
        else if (count == 2)
        {
            memory[address + 1] = hexadecimal_form[count - 1];
            memory[address] = hexadecimal_form[count - 2];
            address = address + 4;
        }
        else if (count == 3)
        {
            memory[address + 2] = hexadecimal_form[count - 1];
            memory[address + 1] = hexadecimal_form[count - 2];
            memory[address] = hexadecimal_form[count - 3];
            address = address + 4;
        }
        else if (count == 4)
        {
            memory[address + 3] = hexadecimal_form[count - 1];
            memory[address + 2] = hexadecimal_form[count - 2];
            memory[address + 1] = hexadecimal_form[count - 3];
            memory[address] = hexadecimal_form[count - 4];
            address = address + 4;
        }
    }
    void manage_label(string fileName, string label_name)
    {

        string line;
        string label = "";
        in_function.open(fileName);
        while (in_function)
        {
            while (label != (label_name + ":"))
            {
                getline(in_function, label);
            }
            getline(in_function, line);

            manage_inst(line);
        }

        in_function.close();
    }

    void manage_inst(string str)
    {

        string word = "";
        ins_string.push("sample");
        int l = str.length();
        char ch[l];

        for (int i = 0; i < l; i++)
        {
            ch[i] = str[i];
        }

        for (int x = 0; x < l; x++)
        {

            while ((ch[x] == ' ') || (ch[x] == ','))
            {
                if (x >= l)
                {
                    break;
                }
                x++;
            }
            word = word + ch[x];
            if (ch[x + 1] == ' ' || ch[x + 1] == ',')
            {
                if (word != "")
                {

                    if (word == "add" || word == "sub" || word == "addi" || word == "subi" || word == "muli" || word == "lw" || word == "sw" || word == "bne" || word == "beq" || word == "bgt" || word == "blt" || word == "jump")
                    {

                        ins_string.push(word);
                        cout << word << endl;
                        word = "";
                    }
                    else
                    {

                        int brac = -1;
                        for (int i = 0; i < word.length(); i++)
                        {
                            if (word[i] == '(')
                                brac = i;
                        }
                        if (brac != -1)
                        {
                            // cout << "working" << endl;
                            string r = "";
                            string temp = "";
                            for (int i = 0; i < brac; i++)
                            {
                                r += word[i];
                            }
                            if (is_word(r))
                            {
                                cout << "word in else: " << r << endl;
                                int i = atoi(&r[1]);
                                ins_int.push(R[i]);
                                // cout << R[i] << endl;
                                word = "";
                            }
                            else
                            {
                                stringstream ss(word);
                                int i = 0;
                                ss >> i;
                                ins_int.push(i);
                                // cout << i << endl;

                                for (int i = brac + 1; i < word.length() - 1; i++)
                                {
                                    temp += word[i];
                                }
                                cout << temp;
                                label.push(temp);
                                word = "";
                            }
                        }
                        else
                        {
                            if (word[0] == 'R')
                            {

                                int i = atoi(&word[1]);
                                ins_int.push(i);

                                // cout << i << endl;
                                word = "";
                            }

                            else if (is_word(word))
                            {
                                if (word != "exit,")
                                {
                                    label.push(word);
                                    cout << "word in isString : " << label.top() << "\n";
                                    word = "";
                                }
                            }
                            else
                            {

                                // cout << "word in else: " << word << endl;
                                stringstream ss(word);
                                int i = 0;
                                ss >> i;
                                ins_int.push(i);
                                // cout << i << endl;
                                word = "";
                            }
                        }
                    }
                }
            }
        }
        int a, b, c;
        if (ins_int.size() == 3)
        {
            c = ins_int.top();
            ins_int.pop();
            b = ins_int.top();
            ins_int.pop();
            a = ins_int.top();
            ins_int.pop();
            // cout << a << " ," << b << " ," << c << endl;
        }
        else if (ins_int.size() == 2)
        {
            b = ins_int.top();
            ins_int.pop();
            a = ins_int.top();
            ins_int.pop();
        }
        //.........................................................................................................
        // if (sstr.size() == 2)
        // {
        // executing each instruction
        if (ins_string.top() == "add")
        {
            R[a] = R[b] + R[c];
            ins_string.pop();
            // cout << "top element after pop : " << sstr.top() << endl;
        }
        else if (ins_string.top() == "sub")
        {
            R[a] = R[b] - R[c];
            ins_string.pop();
            // cout << "top element after pop : " << sstr.top() << endl;
        }
        else if (ins_string.top() == "addi")
        {
            R[a] = R[b] + c;
            ins_string.pop();
            // cout << "top element after pop : " << sstr.top() << endl;
        }

        else if (ins_string.top() == "subi")
        {
            R[a] = R[b] - c;
            ins_string.pop();
            // cout << "top element after pop : " << sstr.top() << endl;
        }
        else if (ins_string.top() == "muli")
        {
            R[a] = R[b] * c;
            ins_string.pop();
            // cout << "top element after pop : " << sstr.top() << endl;
        }
        else if (ins_string.top() == "lw")
        {
            int temp_addr = b;
            if (temp_addr >= 0 && temp_addr < 5000)
            {
                char l[4];
                for (int i = 0; i < 4; i++)
                {
                    l[i] = memory[temp_addr + i];
                }
                int res = convert_char_to_decimal(l);
                R[a] = res;
            }
            ins_string.pop();
        }

        else if (ins_string.top() == "sw")
        {
            int temp_addr = b;
            if (temp_addr >= 0 && temp_addr < 4096)
            {
                store_word_to_memory_address(R[a], temp_addr);
            }

            ins_string.pop();
        }
        else if (ins_string.top() == "bne")
        {
            // cout << a << " " << b << " " << c << endl;
            // cout << "Values of R2 and R3: " << R[2] << "   " << R[3] << endl;
            if (R[a] != R[b])
            {
                in_filename.close();
                in_function.close();
                string s1 = label.top();
                cout << s1 << endl;
                manage_label(filename, s1);
            }
            label.pop();
            // cout << "top element after pop : " << sstr.top() << endl;
        }
        else if (ins_string.top() == "beq")
        {
            // cout << "Values of R2 and R3 (BEQ): " << R[2] << "   " << R[3] << endl;
            if (R[a] == R[b])
            {
                in_filename.close();
                in_function.close();
                string s1 = label.top();
                // cout << "label : " << labH.top() << endl;
                manage_label(filename, s1);
            }
            ins_string.pop();
            // cout << "top element after pop : " << sstr.top() << endl;
        }
        else if (ins_string.top() == "bgt")
        {
            if (R[b] >= R[c])
            {
                R[c] = R[b];
                R[a] = R[16];
            }
        }
        else if (ins_string.top() == "blt")
        {
            if (R[b] <= R[c])
            {
                R[c] = R[b];
                R[a] = R[16];
            }
        }
        else if (ins_string.top() == "jump")
        {

            in_function.close();
            string s2 = label.top();

            manage_label(filename, s2);
        }
    }
};

class Parser
{
    Instruction_mangager IM;

public:
    // reads the file line by line
    void parser(string fn, int n)
    {

        string line;
        string l1;

        if (n >= 5)
        {
            if ((fn[n - 4] == '.' && fn[n - 3] == 'a' && fn[n - 2] == 's' && fn[n - 1] == 'm') || (fn[n - 2] == '.' && fn[n - 1] == 's'))
            {
                in_filename.open(fn);
                // substr strcmp
                while (in_filename)
                {
                    while (l1 != "main:")
                    {
                        getline(in_filename, l1);
                    }
                    getline(in_filename, line);
                    if (line == "exit;")
                        in_filename.close();
                    else
                        IM.manage_inst(line);
                }
                print();
                // in.close();
            }
            else
                cout << "Syntax errors" << endl;
        }
        else if (n >= 3)
        {
            if ((fn[n - 2] == '.' && fn[n - 1] == 'a') || (fn[n - 2] == '.' && fn[n - 1] == 's'))
            {
                in_filename.open(fn);

                while (in_filename)
                {
                    while (l1 != ".main")
                    {
                        getline(in_filename, l1);
                    }
                    getline(in_filename, line);
                    if (line == "exit;")
                    {

                        in_filename.close();
                    }

                    else
                    {
                        IM.manage_inst(line);
                    }
                }
                print();
            }
            else
                cout << "Syntax errors " << endl;
        }
        else
            cout << "Invalid file extension" << endl;
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
        for (int j = 0; j < 5000; j = j + 4)
        {
            cout << "memory[ " << j << " ]  =  0x" << memory[j] << memory[j + 1] << memory[j + 2] << memory[j + 3] << "\t\t ";
        }
    }
};

int main()
{
    for (int i = 0; i < 5000; i++)
    {
        memory[i] = '0';
    }
    Parser p;
    cout << "Enter the file name to be opened : ";
    cin >> filename;
    int n = filename.length();

    p.parser(filename, n);
    // std::cout << "parser worked ";
    cout << R[2];

    return 0;
}