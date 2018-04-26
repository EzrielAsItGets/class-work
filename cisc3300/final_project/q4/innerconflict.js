function getRandomColor() {
  var letters = '0123456789ABCDEF';
  var color = '#';
  for (var i = 0; i < 6; i++) {
    color += letters[Math.floor(Math.random() * 16)];
  }
  return color;
}

function onClick() {
  for(i = 1; i < 13; i++){
	  div1 = document.createElement('div');
    div1.style.position = "fixed";
	  div1.style.left = 50 + (i*10);
	  div1.style.top = 50 + (i*10);
	  div1.style.width = 400 - (i*20);
	  div1.style.height = 400 -(i*20);
	  body.appendChild(div1);
	  if(i%2 > 0)
		  div1.style.backgroundColor = getRandomColor();
	  else
		  div1.style.backgroundColor = getRandomColor();
  }
}
button1 = document.querySelector('button');
	button1.addEventListener('click', onClick);
