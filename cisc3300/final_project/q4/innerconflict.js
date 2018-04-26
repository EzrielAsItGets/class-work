function onClick() {
  for(i = 1; i < 13; i++){
	  div1 = document.createElement('div');
	  div1.style.left = 50 + (i*10);
	  div1.style.top = 50 + (i*10);
	  div1.style.width = 400 - (i*10);
	  div1.style.height = 400 -(i*10);
	  body.appendChild(div1);
	  if(i%2 > 0)
		  div1.style.backgroundColor = (34,12,64);
	  else
		  div1.style.backgroundColor = (76,0,34);
  }
}	
button1 = document.querySelector('button');
	button1.addEventListener('click', onClick);
