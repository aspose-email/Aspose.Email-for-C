<?php

$message = ''; 
if (isset($_POST['uploadBtn']) && $_POST['uploadBtn'] == 'Upload')
{
  if (isset($_FILES['uploadedFile']) && $_FILES['uploadedFile']['error'] === UPLOAD_ERR_OK)
  {
    // get details of the uploaded file
    $fileName = $_FILES['uploadedFile']['name'];
    $fileTmpPath = $_FILES['uploadedFile']['tmp_name'];
    $tmpDir = dirname($fileTmpPath);

    $newFormat = $_POST['saveAs'];

    $newName = pathinfo($fileName)['filename'] . "." . $newFormat;
    $newPath = $tmpDir .  DIRECTORY_SEPARATOR . $newName;
    error_log ("aspose_email_convert($fileTmpPath, $newPath, $newFormat)");
    $result = aspose_email_convert($fileTmpPath, $newPath, strtolower($newFormat));
    error_log ("aspose_email_convert result : $result");

    header("Content-Description: File Transfer"); 
    header("Content-Type: application/octet-stream"); 
    header("Content-Disposition: attachment; filename=\"". $newName ."\""); 

    readfile ($newPath);

    exit(); 


  }
  else
  {
    $message = 'There is some error in the file upload. Please check the following error.<br>';
    $message .= 'Error:' . $_FILES['uploadedFile']['error'];
  }
}
