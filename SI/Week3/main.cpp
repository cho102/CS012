shadow::shadow()
{
    gold = 0;
    champ = "no champion";
}

shadow::shadow(string name)
{
    if (name == "Shadow Man")
    {
        gold = 500;
        
    }
    else
    {
        gold = 0;
        champ = "no champion";
    }
}