function performClick( root, obj ) {
  // JavaScript Function Handler
  print("JavaScript in a Signal Handler");
  var max = root.width - obj.width
  obj.x = (obj.x === 0) ? max : 0
}

function swapColor( obj ) {
  return obj.pressed ? "orange" : "gray"
}
