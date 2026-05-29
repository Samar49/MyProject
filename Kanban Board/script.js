const todo=document.querySelector('#todo');
const progress=document.querySelector('#progress');
const done=document.querySelector('#done');

const tasks=document.querySelectorAll('.task');

tasks.forEach(task=> {
    task.addEventListener("drag",(e)=>{
    
})
})

function addDragEventOnColumn(column){
    column.addEventListener('dragenter',(e)=>{
        column.classList.add("hover-over")
    })
    column.addEventListener('dragleave',(e)=>{
        column.classList.remove("hover-over")
    })
    column.addEventListener('dragover',(e)=>{
        e.preventDefault();
    })
    column.addEventListener('drop',(e)=>{
        e.preventDefault();
        console.log("Dropped",e);
    })
    
}

addDragEventOnColumn(todo);
addDragEventOnColumn(progress)
addDragEventOnColumn(done)


