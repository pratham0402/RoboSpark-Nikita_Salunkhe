<?php

include('db.php');

if(isset($_POST['submit'])){
    $id = $_POST['id'];
    
    $query = " SELECT * FROM `task` WHERE `stud_id`='$id' ";
    $run = mysqli_query($con, $query);
    $row = mysqli_num_rows($run);

    if ($row == 1){
        $current = mysqli_fetch_assoc($run);
        $name = $current['stud_name'];
        $branch = $current['stud_branch'];
        $cgpa = $current['cgpa'];
        echo "
        <!DOCTYPE html>
        <head>
            <title>Document</title>
            <link rel='stylesheet' href='student.css'>
            <link rel='icon' href='images/boy1.png'>
        </head>
        <body>
        <div class='portal'>
            <h4><em>Student Found</em></h4>
            <p>Student ID is: $id</p>
            <p>Student name is: $name</p>
            <p>Branch: $branch</p>
            <p>CGPA: $cgpa</p>
        </div>
        </body>
        </html>
        ";
    }
    else{
        echo "unknown id entered";
    }
    
}

?>