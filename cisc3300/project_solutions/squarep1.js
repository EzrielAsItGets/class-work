function createImage(src)
 {
  const image = document.createElement('img');
  
image.src = src;
 
 return image;
}

function addElement(event) {
photoSrc="bfly1.gif";
const image = createImage(photoSrc);
 
event.currentTarget.appendChild(image);
  

}

const section1 = document.querySelectorAll('#flex-container div');
console.log(section1.length);
for (let i = 0; i < section1.length; i++) 
{
  
 

 
 section1[i].addEventListener('click', addElement);

}
 

 


