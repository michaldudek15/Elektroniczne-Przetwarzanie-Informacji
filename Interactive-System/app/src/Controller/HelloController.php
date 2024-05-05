<?php
/**
 * Hello controller.
 */

namespace App\Controller;

use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Attribute\Route;

/**
 * HelloController class.
 */
class HelloController
{
    /**
     * Index action.
     *
     * @return Response HTTP response
     */
    #[Route('/hello', name: 'hello_index', methods: 'GET')]
    public function index(Request $request): Response
    {
        $name = $request->query->getAlnum('name', 'World');

        return new Response('Hello '.$name.'!');
    }
}
