function Replace()
{
    var new1 = document.getElementById("new");
    var text = document.getElementById('text').value
    new1.innerHTML = text;
    
    if (new1.style.backgroundColor == "cyan") 
    {
        new1.style.backgroundColor = "lavenderblush";
    }
    else
    {
        new1.style.backgroundColor = "cyan";
    }
}

document.getElementById('replace').addEventListener('click', Replace);
