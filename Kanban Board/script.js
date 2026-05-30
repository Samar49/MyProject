let tasksData={}


const todo=document.querySelector('#todo');
const progress=document.querySelector('#progress');
const done=document.querySelector('#done');
const columns=[todo,progress,done];
let dragElement= null;

// creating function to add task- reducing code repeatitive
function addTask(title,desc,column){
    const div=document.createElement("div")
    div.classList.add("task")
    div.setAttribute("draggable","true")

    div.innerHTML=`
            <h2>${title}</h2>
            <p>${desc}</p>
            <button>Delete</button>
            `
    column.appendChild(div)
    div.addEventListener("drag",(e)=>{
        dragElement=div;
    })
    const deleteButton=div.querySelector("button");
    deleteButton.addEventListener("click", ()=>{
        div.remove();
        updateTaskCount();
    })

    return div;
}

// creating function for keeping count of tasks in 3 all section
function updateTaskCount(){
    columns.forEach(col => {
            const tasks = col.querySelectorAll(".task")
            const count = col.querySelector(".right")

            tasksData[col.id]=Array.from(tasks).map(t=>{
                return{
                    title:t.querySelector("h2").innerText,
                    desc: t.querySelector("p").innerText
                }
            })
            // logic to save data on local storage
            localStorage.setItem("tasks",JSON.stringify(tasksData)); 

            count.innerText=tasks.length;
        });
}



// to check if any data is present on local storage
if(localStorage.getItem("tasks")){
    const data=JSON.parse(localStorage.getItem("tasks")); 

    for(const col in data){
        const column =document.querySelector(`#${col}`);
        data[col].forEach(task =>{
            addTask(task.title,task.desc,column);
            
        })
    }
    // function called for keeping count
    updateTaskCount();
}

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

        // function called for keeping count
        updateTaskCount(); 
        
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
    
    addTask(taskTitle,taskDesc,todo);
    
    // function called for keeping count
    updateTaskCount()

    modal.classList.remove("active")
    document.querySelector("#task-title-input").value="";
    document.querySelector("#task-desc-input").value="";


    
})
