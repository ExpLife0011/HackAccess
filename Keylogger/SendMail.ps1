Param( [String]$Att,
       [String]$Subj,
       [String]$Body
       )

Function Send-Email
{
    Param(
                [Parameter('
                Mandatory=$true')]
            [String]$To,
                [Parameter('
                Mandatory=$true')]
            [String]$From,
                [Parameter('
                Mandatory=$true')]
            [String]$Password,
                [Parameter('
                Mandatory=$true')]
            [String]$Subject,
                [Parameter('
                Mandatory=$true')]
            [String]$Body,
                [Parameter('
                Mandatory=$true')]
            [String]$attachment
            )
try 
{
    $Msg = New-Object System.Net.Mail.MailMessage($From,$To,$Subject,$Body)
    $Srv = "smtp.gmail.com"
    if($attachment -ne $null) 
    {
        try
        {
            $Attachments = $attachment -split ("\:\:");
            forEach($val in $Attachments)
            {
                $attch = New-Object System.Net.Mail.Attachment($val)
                $Msg.Attachments.Add($attch
            }
        }
    }
}

}           