
function searchClick() {
var searchPhrase = document.getElementById("searchtext").value;
var main = document.querySelector(' #main ');
var mainParas = main.querySelectorAll('p');

for (var i = 0; i < mainParas.length; i++) {
     
console.log(i," element number");
/*if (mainParas[i].textContent.indexOf(searchPhrase) >= 0)
 { mainParas[i].classList.add('highlighted');}    // highlight 
 else {
 mainParas[i].classList.remove('highlighted');	// un-highlight
         }  */

      if (mainParas[i].textContent.indexOf(searchPhrase) >= 0)     {
       lind =mainParas[i].textContent.indexOf(searchPhrase);
       lind1 = lind + searchPhrase.length -1 ;
      console.log(lind,"  ",lind1);

       newtext1 ="";
       newtext2 ="";
       newtext3 ="";
       for (j=0;j<mainParas[i].textContent.length;j++) {
           if (j >= 0  &&  j < lind  ) { newtext1 = newtext1 + mainParas[i].textContent.substr(j,1);
                                                                        console.log(newtext1,"  the word"); }                
            else if (j >= lind  &&  j <= lind1  ) { newtext2 = newtext2 + mainParas[i].textContent.substr(j,1);}
                                                                                        
                          
                else             {newtext3 = newtext3 + mainParas[i].textContent.substr(j,1); }
                             
                                                                             }
                  console.log(newtext1," newtext1 ",newtext2," newtext2",newtext3," newext3");

                 mainParas[i].textContent = newtext1 + newtext2 + newtext3;    
                 /*console.log(newtext," this is the new paragraph");*/  

            newsec =document.querySelector(' #resultsection');

                 p1 =document.createElement('p');
                 p1.textContent = newtext1;
                 newsec.appendChild(p1);

                p2 =document.createElement('p');
                 p2.textContent = newtext2;
                 p2.classList.add('highlighted');
                 p2.classList.add('parlen');
              newsec.appendChild(p2);

                 p3 =document.createElement('p');
                 p3.textContent = newtext3;
                newsec.appendChild(p3);          

                                                                                                 }
                                                                  }
                 
                 
          
                                 }

  const document1 = document.querySelector('#searchbutton');

  /*document1= document.getElementById("searchbutton");*/  
document1.addEventListener('click',searchClick); 

/*modalView.addEventListener('click', onModalClick);*/
