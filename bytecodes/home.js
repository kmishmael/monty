
var isValid = function(s) {
    let stack = [];
    for (let p of s)
    {
        if (p == '(' || p == '{' || p == '[')
        {
            stack.push(p);
        }
        else {
            let open = stack[stack.length - 1];
            switch(p)
            {
                case ')':
                    if (open == '(')
                    {
                        stack.pop();
                    }
                    else {
                        return false
                    }
                    break;
                case '}':
                    if (open == '{')
                    {
                        stack.pop();
                    }
                    else {
                        return false
                    }
                    break;
                case ']':
                    if (open == '[')
                    {
                        stack.pop();
                    }
                    else {
                        return false
                    }       
                    break;                       
            }
            
        }
    }
    if (stack.length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
};
let s = " "
s.split(" ")
.toLowerCase() .replace([^a-zA-Z0-9]+/g,"")