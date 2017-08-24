var t;
function idleOut() {
  window.location = 'index.html';
}
function resetTimer() {
  console.log("Reset");
  clearTimeout(t);
  t = setTimeout(idleOut, 10000)
}
document.onmousemove = resetTimer;
document.onkeypress = resetTimer;