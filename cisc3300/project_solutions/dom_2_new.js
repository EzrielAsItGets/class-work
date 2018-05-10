
function searchClick() {
var searchPhrase = document.getElementById("searchtext").value;
var main = document.querySelector(' #main ');
var mainParas = main.querySelectorAll('p');

for (var i = 0; i < mainParas.length; i++) {

if (mainParas[i].textContent.indexOf(searchPhrase) >= 0)
 { mainParas[i].classList.add('highlighted');}    // highlight 
 else {
 mainParas[i].classList.remove('highlighted');	// un-highlight
         }

                                                            }
                 
                                 }

  const document1 = document.querySelector('#searchbutton');

  /*document1= document.getElementById("searchbutton");*/  
document1.addEventListener('click',searchClick); 

/*modalView.addEventListener('click', onModalClick);*/
