let tasksData={}


const todo=document.querySelector('#todo');
const progress=document.querySelector('#progress');
const done=document.querySelector('#done');
const columns=[todo,progress,done];
let dragElement= null;

const tasks=document.querySelectorAll('.task');

tasks.forEach(task=> {
    task.addEventListener("drag",(e)=>{
        // console.log("dragging",e)
        dragElement=task;
    
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
        console.log("dropped",dragElement,column);
        column.appendChild(dragElement);
        column.classList.remove("hover-over");

        columns.forEach(col => {
            const tasks = col.querySelectorAll(".task")
            const count = col.querySelector(".right")
            count.innerText=tasks.length;
        });


    })
    
}

addDragEventOnColumn(todo);
addDragEventOnColumn(progress)
addDragEventOnColumn(done)

// below section is my logic for Modal
const toggleModalButton = document.querySelector('#toggle-modal')
const modalBg=document.querySelector(".modal .bg")
const modal=document.querySelector(".modal")

const addTaskButton=document.querySelector("#add-new-task")

toggleModalButton.addEventListener("click",()=>{
    modal.classList.toggle("active")
})
modalBg.addEventListener("click",()=>{
    modal.classList.remove("active")
})

// --------------------------------------------

addTaskButton.addEventListener("click",()=>{
    const taskTitle=document.querySelector("#task-title-input").value
    const taskDesc=document.querySelector("#task-desc-input").value
    
    const div=document.createElement("div")
    div.classList.add("task")
    div.setAttribute("draggable","true")
    div.innerHTML=`
        <h2>${taskTitle}</h2>
        <p>${taskDesc}</p>
        <button>Delete</button>
    `
    todo.appendChild(div)
    
    columns.forEach(col => {
            const tasks = col.querySelectorAll(".task")
            const count = col.querySelector(".right")

            tasksData[col.id]=tasks.map(t=>{})

            count.innerText=tasks.length;
        });

    modal.classList.remove("active")
div.addEventListener("drag",(e)=>{
    dragElement=div;
})

})
