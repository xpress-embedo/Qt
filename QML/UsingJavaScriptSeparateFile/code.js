var Root
var Box

function performClick( root, obj ) {
  // JavaScript Function Handler
  print("JavaScript in a Signal Handler");
  var max = root.width - obj.width
  obj.x = (obj.x === 0) ? max : 0
}

function swapColor( obj ) {
  return obj.pressed ? "orange" : "gray"
}

function startup( croot, cbox) {
  print("Starting!!!")
  Root = croot
  Box = cbox
}

function clicked( mouse ) {
  print("Mouse Clicked");
  performClick( Root, Box);
}
