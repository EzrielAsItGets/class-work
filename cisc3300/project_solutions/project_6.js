function onClick( ) {
 text1 = document.getElementById("texta").value;
para= document.querySelector('p');
para.textContent = text1;

 
     if ( i % 2  ==  0) {para.style.backgroundColor = "lavender";}
     else {para.style.backgroundColor=  "thistle";}
     i = i +1;
                      }

  var i=0;

  button1=document.querySelector('button');
  button1.addEventListener('click',onClick);

 
          