
static char *saved_s = 0;

// if s == 0 then previously saved string is to be parsed
// delim - set of delimiter characters - may change each call of strtok
char *strtok(char *s, char *delim)  {

    if(s == 0) // pick up saved result
        s = saved_s;
    if(s == 0)
        return 0;    

    char *ps = s; // skip leading delimiter chars
    for(; *ps != 0; ps++) {
        const char *pd = delim;
        for(; *pd != 0; pd++)
            if(*ps == *pd)
                break;
        if(*pd == 0) // all delimiters enumerated
            break; 
    }

    s = ps; // s is the beginning of next token
    if(*s == 0) { // empty string: no more tokens found
        saved_s = s;
        return 0; 
    }

    // now find the end of the token    
    for(ps = s + 1; *ps != 0; ps++) {
        const char *pd = delim;
        for(; *pd != 0; pd++)
            if(*ps == *pd)
                break;
        if(*pd != 0)
            break;
    }
    // now ps points either to '\0' or to the first delimiter
    saved_s = ps;
    if(*ps != 0) {
        saved_s++;
        *ps = '\0'; // put terminating 0
    }
    return ps;
}
