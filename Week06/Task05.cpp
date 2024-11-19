class Solution {
public:
	bool isOperation(const std::string& ch)
	{
		return ch == "+" || ch == "-" || ch == "*" || ch == "/";
	}

	int calculate(int stop, int ftop, const string& op)
	{
		if (op == "+")
		{
			return stop + ftop;
		}
		else if (op == "-")
		{
			return stop - ftop;
		}
		else if (op == "*")
		{
			return stop * ftop;
		}
		else
		{
			return stop / ftop;
		}
	}

	int evalRPN(std::vector<std::string>& tokens)
	{
		std::stack<int> st;

		for (int i = 0; i < tokens.size(); i++)
		{
			if (!isOperation(tokens[i]))
			{
				st.push(stoi(tokens[i]));
				continue;
			}
			else
			{
				int ftop = st.top();
				st.pop();
				int stop = st.top();
				st.pop();

				st.push(calculate(stop, ftop, tokens[i]));
			}
		}

		return st.top();
	}
};