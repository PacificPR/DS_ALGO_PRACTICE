bool isAnagram(string c, string d){
    
    // Your code here
    int arr1[256]={0};
    int arr2[256]={0};
    if(c.length()!=d.length())
    {
        return 0;
    }
    for(int i=0; i<c.length(); i++)
    {
        arr1[int(c[i])]++;
        arr2[int(d[i])]++;
    }
    for(int i=0; i<256; i++)
    {
        if(arr1[i] != arr2[i])
        {
            return 0;
        }
    }
    return 1;
}
